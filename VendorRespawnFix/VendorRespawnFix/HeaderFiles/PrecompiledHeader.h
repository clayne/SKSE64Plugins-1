#pragma once

#include <cstdint>    // Fixed width integer types
#include <filesystem> // Filesystem library
#include <memory>     // std::addressof, std::make_shared
#include <utility>    // std::move

#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_INFO

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/spdlog.h>

#include "Shared/SKSE/SKSE.h"
#include "Shared/Skyrim/Skyrim.h"
