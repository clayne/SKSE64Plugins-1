#include "PrecompiledHeader.h"

#include "ScrambledBugsInterface.h"
#include "Serialization.h"
#include "Settings.h"
#include "Shared/Relocation/Module.h"
#include "Shared/Utility/Conversion.h"



namespace ScrambledBugs
{
	namespace Logger
	{
		void Load()
		{
			auto path   = std::filesystem::path(Relocation::DynamicLinkLibrary::GetSingleton().GetPath()).replace_extension("log");
			auto logger = spdlog::basic_logger_mt(path.string(), path.string(), true);

			logger->flush_on(spdlog::level::info);
			logger->set_level(spdlog::level::info);
			logger->set_pattern("[%Y-%m-%d %T.%e %z] [%l] [%t] [%s:%#] %v");

			spdlog::set_default_logger(std::move(logger));
		}
	}

	void PostLoad()
	{
		auto& settings = Settings::GetSingleton();

		SPDLOG_INFO("Post Loading...\n{}", settings.Serialize().dump(1, '\t'));

		settings.PostLoad();

		SPDLOG_INFO("Post Loaded.\n{}", settings.Serialize().dump(1, '\t'));
	}

	void MessageHandler(SKSE::MessagingInterface::Message* message)
	{
		switch (message->type)
		{
			case SKSE::MessagingInterface::kPostLoad:
			{
				PostLoad();

				break;
			}
		}
	}

	void Load()
	{
		if (!SKSE::Storage::GetSingleton().GetMessagingInterface()->RegisterListener(MessageHandler))
		{
			return;
		}

		const auto* serializationInterface = SKSE::Storage::GetSingleton().GetSerializationInterface();

		serializationInterface->SetUniqueID(Serialization::kUniqueID);
		serializationInterface->SetLoadCallback(std::addressof(Serialization::LoadGame));
		serializationInterface->SetSaveCallback(std::addressof(Serialization::SaveGame));

		auto& settings = Settings::GetSingleton();

		SPDLOG_INFO("Loading...\n{}", settings.Serialize().dump(1, '\t'));

		settings.Load();

		SPDLOG_INFO("Loaded.\n{}", settings.Serialize().dump(1, '\t'));
	}
}

#ifdef SKYRIM_ANNIVERSARY_EDITION
extern "C" __declspec(dllexport) constinit SKSE::PluginVersionData SKSEPlugin_Version{
	.pluginVersion   = Utility::Conversion::ToUnderlying(ScrambledBugs::Interface::Version::Version22),
	.pluginName      = "Scrambled Bugs",
	.author          = "KernalsEgg",
	.addressLibrary  = true,
	.compatible16629 = true
};
#endif

extern "C" __declspec(dllexport) bool __cdecl SKSEPlugin_Load(SKSE::Interface* loadInterface)
{
	ScrambledBugs::Logger::Load();
	SKSE::Storage::GetSingleton().Load(loadInterface);
	ScrambledBugs::Load();

	return true;
}
