def read_config():
    global config_data_yaml
    try:
        this_dir = os.getcwd()
        config_file_location = this_dir + "/config.yaml"
        config_data = open(config_file_location)
        config_data_yaml = yaml.load(config_data, Loader=yaml.FullLoader)

        try:
            glob_name_project = config_data_yaml["name_project"]
        except:
            print(" ERROR Not find value name_project in " + config_file_location)

        try:
            glob_description = config_data_yaml["description"]
        except:
            print(" WARNING Not find value description in " + config_file_location)

        try:
            glob_build_dir = config_data_yaml["build_dir"]
        except:
            print(" ERROR Not find value build_dir in " + config_file_location)

        try:
            glob_name_build = config_data_yaml["name_build"]
        except:
            print(" ERROR Not find value name_build in " + config_file_location)

        try:
            glob_build_system_exe = config_data_yaml["build_system_exe"]
        except:
            print(" ERROR Not find value build_system_exe in " + config_file_location)

        try:
            glob_c_compiler = config_data_yaml["c_compiler"]
        except:
            print(" ERROR Not find value c_compiler in " + config_file_location)

        try:
            glob_cxx_compiler = config_data_yaml["cxx_compiler"]
        except:
            print(" ERROR Not find value cxx_compiler in " + config_file_location)

        try:
            glob_build_system = config_data_yaml["build_system"]
        except:
            print(" ERROR Not find value build_system in " + config_file_location)

        try:
            glob_cmake_flags = config_data_yaml["cmake_flags"]
        except:
            print(" WARNING Not find value cmake_flags in " + config_file_location)

        try:
            glob_build_system_flags = config_data_yaml["build_system_flags"]
        except:
            print(" WARNING Not find value build_system_flags in " + config_file_location)

    except:
        print("ERROR This not is a Moon Project")