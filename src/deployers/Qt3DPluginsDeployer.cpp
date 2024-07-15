// system headers
#include <filesystem>

// library headers
#include <linuxdeploy/log/log.h>

// local headers
#include "Qt3DPluginsDeployer.h"

using namespace linuxdeploy::plugin::qt;
using namespace linuxdeploy::log;

namespace fs = std::filesystem;

bool Qt3DPluginsDeployer::deploy() {
    // calling the default code is optional, but it won't hurt for now
    if (!BasicPluginsDeployer::deploy())
        return false;

    ldLog() << "Deploying Qt 3D plugins" << std::endl;

    for (fs::directory_iterator i(qtPluginsPath / "geometryloaders"); i != fs::directory_iterator(); ++i) {
        if (!appDir.deployLibrary(*i, appDir.path() / "usr/plugins/geometryloaders/"))
            return false;
    }

    for (fs::directory_iterator i(qtPluginsPath / "sceneparsers"); i != fs::directory_iterator(); ++i) {
        if (!appDir.deployLibrary(*i, appDir.path() / "usr/plugins/sceneparsers/"))
            return false;
    }

    return true;
}
