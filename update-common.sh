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

if [ -z $1 ]; then
    echo "usage: $0 <build number>"
    echo
    echo "The build number should be from a *snap* [not a buildkick] of git_main-build-tools-release."
    echo "https://android-build.googleplex.com/coastguard/branch/git_main-build-tools-release/#/request/"
    echo
    echo "Don't forget to repo start first!"
    exit 1
fi

readonly BUILD_NUMBER=$1

cd "$(dirname $0)"

if ! git diff HEAD --quiet; then
    echo "must be run with a clean prebuilts/build-tools project"
    exit 1
fi

readonly tmpdir=$(mktemp -d)

function finish {
    if [ ! -z "${tmpdir}" ]; then
        rm -rf "${tmpdir}"
    fi
}
trap finish EXIT

function fetch_artifact() {
    # Include the -branch argument to fetch_artifact to enforce that the
    # prebuilts come from the release branch and not the dev branch.
    /google/data/ro/projects/android/fetch_artifact --branch git_main-build-tools-release --bid ${BUILD_NUMBER} --target $1 "$2" "$3"
}


function unzip_to() {
    rm -rf "$1"
    mkdir "$1"
    unzip -q -DD -d "$1" "$2"
}
