local function compile()
    print("⚠️ Only use this if you can't compile it with your code editor. ⚠️")
    print("Select the target OS for compilation:")
    print("1. Windows x64")
    print("2. Linux x64")
    
    local choice = io.read()

    local source_files = {
        "./App/src/App.cpp",
    }

    local include_dirs = "-I./App/include"
    local compiler_flags = "-std=c++17"
    local output

    if choice == "1" then
        output = "Binaries/x64/Windows/App"
        print("Compiling your C++ files for Windows...")
    elseif choice == "2" then
        output = "Binaries/x64/Linux/App"
        print("Compiling your C++ files for Linux...")
    else
        print("Invalid choice. Please select 1 for Windows or 2 for Linux.")
        return
    end

    local compile_command = "g++ " .. table.concat(source_files, " ") .. " " .. include_dirs .. " " .. compiler_flags .. " -o " .. output
    local result = os.execute(compile_command)

    if result == 0 then
        print("Compilation successful! Run ./" .. output .. " to execute your program.")
    else
        print("Compilation failed.")
    end
end

compile()
