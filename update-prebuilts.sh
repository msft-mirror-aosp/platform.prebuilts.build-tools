#!/bin/bash -e

# Copyright 2020 Google Inc. All rights reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

cd "$(dirname $0)"

. ./update-common.sh

fetch_artifact linux build-prebuilts.zip "${tmpdir}/linux.zip"
fetch_artifact linux build-common-prebuilts.zip "${tmpdir}/common.zip"
fetch_artifact linux manifest_${BUILD_NUMBER}.xml "${tmpdir}/manifest.xml"
fetch_artifact darwin_mac build-prebuilts.zip "${tmpdir}/darwin.zip"
fetch_artifact linux_musl build-prebuilts.zip "${tmpdir}/linux_musl.zip"
fetch_artifact linux_musl build-arm64-prebuilts.zip "${tmpdir}/linux_arm64.zip"

unzip_to linux-x86 "${tmpdir}/linux.zip"
unzip_to common "${tmpdir}/common.zip"
unzip_to darwin-x86 "${tmpdir}/darwin.zip"
unzip_to linux_musl-x86 "${tmpdir}/linux_musl.zip"
unzip_to linux-arm64 "${tmpdir}/linux_arm64.zip"

cp -f "${tmpdir}/manifest.xml" manifest.xml

git add manifest.xml linux-x86 linux-arm64 linux_musl-x86 darwin-x86 common

git commit -m "Update build-tools to ab/${BUILD_NUMBER}

http://ab/${BUILD_NUMBER}

Test: treehugger"
