TEMPLATE = subdirs
CONFIG = c++17

SUBDIRS += \
    Domain \
    UI \
    UnitTests

DOMAIN.depends =
TESTS.depend = DOMAIN
