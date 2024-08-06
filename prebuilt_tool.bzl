# Copyright (C) 2024 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#       http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

"""Declares a tool that fits multiple platforms/config settings."""

load("@bazel_skylib//rules:native_binary.bzl", "native_binary")

visibility("private")

def prebuilt_tool(
        name,
        actual = None,
        **kwargs):
    """Declares a tool that fits multiple platforms/config settings.

    Args:
        name: name of the target
        actual: Non-configurable. Name of the binary below `<platform>/bin`. Defaults to name.
        **kwargs: additional arguments to the internal target.
    """

    if actual == None:
        actual = name

    native_binary(
        name = name,
        src = select({
            "@platforms//os:macos": "darwin-x86/bin/" + actual,
            "@platforms//os:linux": "linux-x86/bin/" + actual,
            "//build/bazel_common_rules/platforms/os_arch:linux_musl_x86": "linux_musl-x86/bin/" + actual,
            "//build/bazel_common_rules/platforms/os_arch:linux_musl_x86_64": "linux_musl-x86/bin/" + actual,
        }),
        out = name,
        target_compatible_with = select({
            "@platforms//os:macos": [],
            "@platforms//os:linux": [],
            "//build/bazel_common_rules/platforms/os_arch:linux_musl_x86": [],
            "//build/bazel_common_rules/platforms/os_arch:linux_musl_x86_64": [],
            "//conditions:default": ["@platforms//:incompatible"],
        }),
        **kwargs
    )
