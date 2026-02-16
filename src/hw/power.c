/*
 *  SPDX-License-Identifier: LGPL-2.1-or-later
 *
 *  TRX Brass LVGL GUI
 *
 *  Copyright (c) 2022-2025 Belousov Oleg aka R1CBU
 *
 *  电源控制模块 - Linux系统级电源管理
 *  功能：关机、重启、电源状态检测
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/reboot.h>
#include <linux/reboot.h>
#include <sys/stat.h>

#include "lvgl/lvgl.h"
#include "power.h"

// ============ 电源状态 ============
static bool initialized = false;

// ============ 检查电源是否连接 ============
static bool check_power_source() {
    struct stat st;

    // 检查是否有电源适配器连接（通过 sysfs）
    if (stat("/sys/class/power_supply/AC/online", &st) == 0) {
        int fd = open("/sys/class/power_supply/AC/online", O_RDONLY);
        if (fd >= 0) {
            char buf[8];
            read(fd, buf, sizeof(buf));
            close(fd);
            return (buf[0] == '1');
        }
    }

    // 如果无法检测，假设有电源
    return true;
}

// ============ 执行系统关机 ============
static void execute_shutdown() {
    sync();  // 同步文件系统

    // 尝试使用系统调用关机
    reboot(LINUX_REBOOT_CMD_POWER_OFF);

    // 如果失败，使用 system 命令
    system("poweroff -f");
}

// ============ 执行系统重启 ============
static void execute_reboot() {
    sync();  // 同步文件系统

    // 尝试使用系统调用重启
    reboot(LINUX_REBOOT_CMD_RESTART);

    // 如果失败，使用 system 命令
    system("reboot -f");
}

// ============ 电源初始化 ============
void power_init() {
    if (initialized) {
        return;
    }

    LV_LOG_INFO("Power control initialized");

    initialized = true;
}

// ============ 关机 ============
void power_shutdown() {
    LV_LOG_INFO("Shutting down system...");

    // 给系统一些时间完成清理工作
    sleep(1);

    execute_shutdown();
}

// ============ 重启 ============
void power_reboot() {
    LV_LOG_INFO("Rebooting system...");

    // 给系统一些时间完成清理工作
    sleep(1);

    execute_reboot();
}

// ============ 检查电源是否连接 ============
bool power_is_connected() {
    return check_power_source();
}
