#!/bin/bash -e

# Copyright 2026 Google Inc. All rights reserved.
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

fetch_artifact linux manifest_${BUILD_NUMBER}.xml "${tmpdir}/manifest.xml"
MUSL_TRIPLES="x86_64-unknown-linux-musl i686-unknown-linux-musl aarch64-unknown-linux-musl arm-unknown-linux-musleabihf"
for triple in ${MUSL_TRIPLES}; do
    fetch_artifact linux_musl musl-sysroot-${triple}.zip "${tmpdir}/musl-sysroot-${triple}.zip"
done
GLIBC_TRIPLES="x86_64-unknown-linux-gnu i386-unknown-linux-gnu aarch64-unknown-linux-gnu arm-unknown-linux-gnueabihf"
for triple in ${GLIBC_TRIPLES}; do
    fetch_artifact linux glibc-sysroot-${triple}.zip "${tmpdir}/glibc-sysroot-${triple}.zip"
done

sysroot_dirs=""
for triple in ${MUSL_TRIPLES}; do
    unzip_to sysroots/${triple} "${tmpdir}/musl-sysroot-${triple}.zip"
    sysroot_dirs="${sysroot_dirs} sysroots/${triple}"
done
for triple in ${GLIBC_TRIPLES}; do
    unzip_to sysroots/${triple} "${tmpdir}/glibc-sysroot-${triple}.zip"
    sysroot_dirs="${sysroot_dirs} sysroots/${triple}"
done

cp -f "${tmpdir}/manifest.xml" sysroots/manifest.xml

git add sysroots/manifest.xml ${sysroot_dirs}
git commit -m "Update sysroots to ab/${BUILD_NUMBER}

http://ab/${BUILD_NUMBER}

Test: treehugger"
