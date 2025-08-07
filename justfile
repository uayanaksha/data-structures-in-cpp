#!/usr/bin/env just --justfile

cmd := "g++ -std=c++17 -lgtest -lgtest_main -pthread"

build NAME:
    #!/usr/bin/env bash
    set -euo pipefail
    mkdir -p {{NAME}}
    {{cmd}} -o {{NAME}}/{{NAME}}.test.out {{NAME}}/{{NAME}}.test.cpp

run NAME: (build NAME)
    #!/usr/bin/env bash
    set -euo pipefail
    ./{{NAME}}/{{NAME}}.test.out

clean NAME:
    #!/usr/bin/env bash
    rm -f {{NAME}}/{{NAME}}.test.out

# Run all tests in a directory
run-all:
    #!/usr/bin/env bash
    set -euo pipefail
    find . -name "*.test.out" -executable -exec {} \;
