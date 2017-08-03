TEMPLATE = subdirs

SUBDIRS += \
    app \
    common \
    tests

app.subdir = src/app
tests.subdir = src/tests
common.subdir  = src/common

app.depends = common
tests.depends = common

