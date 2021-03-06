# A simple Makefile providing shortcuts to NPM tasks defined in package.json
# Why? Because, for developers working in multiple Stencila repos, using alternative
# languages (e.g. Javascript, R, Python), it's nice to have a consistent command line
# interface for common development tasks (e.g. `make setup`, `make run`, `make docs`)

all: setup lint cover build docs

setup:
	npm install

run:
	npm start

lint:
	npm run lint

test:
	npm test

test-browser:
	npm run test-browser

test-integration:
	npm run build
	./tests/integration.sh

test-one:
	npm run test-one -- $(FILE)

# TODO: bring back integration test
# test-all: test test-integration
test-all: test

cover:
	npm run cover

build:
	npm run build

docs-serve:
	npm run docs-serve

clean:
	node make clean
