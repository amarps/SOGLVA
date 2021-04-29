#pragma once

#include "SOGLVA.h"
#include <memory>

#ifdef SOGLVA_EXPORTS
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __declspec(dllimport)
#endif

static std::unique_ptr<Soglva> application;
