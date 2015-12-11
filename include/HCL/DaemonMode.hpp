#pragma once

#ifndef HCL_DAEMONMODE_HPP
#define HCL_DAEMONMODE_HPP

/**
 * This file is a part of Haont Common Library (HCL) [Daemon module]
 * Contains the declaration of DaemonMode
 * Declares requested daemon running mode, actualy is a flag container
 *
 * Flags:
 * 0x01: run application
 * 0x02: daemonize (no sense without 0x01)
 * 0x04: stop application
 *
 * No flag should cause showing help message
 *
 * @project HCL
 * @author k1-801
 */

#include <stdint.h>

#define HCL_HELP             0x00
#define HCL_NODAEMON         0x01
#define HCL_DAEMON           0x03
#define HCL_STOP             0x04
#define HCL_RESTART_NODAEMON 0x05
#define HCL_RESTART          0x07

namespace Hcl
{
    typedef uint64_t DaemonMode;
}

#endif // HCL_DAEMONMODE_HPP
