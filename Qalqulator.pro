TEMPLATE = subdirs
CONFIG = c++17

SUBDIRS += \
    Domain \
    UnitTests

DOMAIN.depends =
TESTS.depend = DOMAIN
