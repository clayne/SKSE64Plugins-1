#pragma once

#include <array>      // std::array
#include <cstdint>    // Fixed width integer types
#include <filesystem> // Filesystem library
#include <format>     // std::format
#include <memory>     // std::addressof
#include <optional>   // std::make_optional, std::nullopt, std::optional
#include <random>     // std::mt19937, std::random_device, std::uniform_int_distribution
#include <utility>    // std::make_pair, std::move, std::pair

#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_INFO

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/spdlog.h>

#include "Shared/SKSE/SKSE.h"
#include "Shared/Skyrim/Skyrim.h"
