#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Proteus {
	class PROTEUS_API Log
	{
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	public:
		Log();
		virtual ~Log();
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger(){ return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger(){ return s_ClientLogger; }

	};
}




#ifdef PROTEUS_DEBUG

// Core Log macros
#define PROTEUS_CORE_TRACE(...) ::Proteus::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define PROTEUS_CORE_INFO(...) ::Proteus::Log::GetCoreLogger()->info(__VA_ARGS__);
#define PROTEUS_CORE_WARN(...) ::Proteus::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define PROTEUS_CORE_ERROR(...) ::Proteus::Log::GetCoreLogger()->error(__VA_ARGS__);
#define PROTEUS_CORE_FATAL(...) ::Proteus::Log::GetCoreLogger()->fatal(__VA_ARGS__);

// Client Log macros

#define PROTEUS_TRACE(...) ::Proteus::Log::GetClientLogger()->trace(__VA_ARGS__);
#define PROTEUS_INFO(...) ::Proteus::Log::GetClientLogger()->info(__VA_ARGS__);
#define PROTEUS_WARN(...) ::Proteus::Log::GetClientLogger()->warn(__VA_ARGS__);
#define PROTEUS_ERROR(...) ::Proteus::Log::GetClientLogger()->error(__VA_ARGS__);
#define PROTEUS_FATAL(...) ::Proteus::Log::GetClientLogger()->fatal(__VA_ARGS__);

#else

// Core Log macros
#define PROTEUS_CORE_TRACE(...)
#define PROTEUS_CORE_INFO(...)
#define PROTEUS_CORE_WARN(...)
#define PROTEUS_CORE_ERROR(...)
#define PROTEUS_CORE_FATAL(...)

// Client Log macros

#define PROTEUS_TRACE(...)
#define PROTEUS_INFO(...)
#define PROTEUS_WARN(...)
#define PROTEUS_ERROR(...)
#define PROTEUS_FATAL(...)

#endif // DEBUG