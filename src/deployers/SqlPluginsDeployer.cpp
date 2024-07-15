// system headers
#include <filesystem>

// library headers
#include <linuxdeploy/log/log.h>

// local headers
#include "SqlPluginsDeployer.h"

using namespace linuxdeploy::plugin::qt;
using namespace linuxdeploy::log;

namespace fs = std::filesystem;

bool SqlPluginsDeployer::deploy() {
    // calling the default code is optional, but it won't hurt for now
    if (!BasicPluginsDeployer::deploy())
        return false;

    ldLog() << "Deploying SQL plugins" << std::endl;

    for (fs::directory_iterator i(qtPluginsPath / "sqldrivers"); i != fs::directory_iterator(); ++i) {
        if (!appDir.deployLibrary(*i, appDir.path() / "usr/plugins/sqldrivers/"))
            return false;
    }

    return true;
}
