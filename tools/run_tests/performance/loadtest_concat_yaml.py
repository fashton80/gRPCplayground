#!/usr/bin/env python3
# Copyright 2021 The gRPC Authors
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

# Helper script to concatenate YAML files.
#
# This script concatenates multiple YAML files into a single multipart file.
# Input files are not parsed but processed as strings. This is a convenience
# script to concatenate output files generated by multiple runs of
# loadtest_config.py.

import argparse
import sys
from typing import Iterable


def gen_content_strings(input_files: Iterable[str]) -> Iterable[str]:
    if not input_files:
        return

    with open(input_files[0]) as f:
        content = f.read()
    yield content

    for input_file in input_files[1:]:
        with open(input_file) as f:
            content = f.read()
        yield '---\n'
        yield content


def main() -> None:
    argp = argparse.ArgumentParser(description='Concatenates YAML files.')
    argp.add_argument('-i',
                      '--inputs',
                      action='extend',
                      nargs='+',
                      type=str,
                      required=True,
                      help='Input files.')
    argp.add_argument(
        '-o',
        '--output',
        type=str,
        help='Concatenated output file. Output to stdout if not set.')
    args = argp.parse_args()

    with open(args.output, 'w') if args.output else sys.stdout as f:
        for content in gen_content_strings(args.inputs):
            print(content, file=f, sep='', end='')


if __name__ == '__main__':
    main()
