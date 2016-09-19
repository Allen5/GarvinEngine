new_git_repository(
	name = "googletest",
	remote = "https://github.com/google/googletest.git",
	tag = "release-1.7.0",
	build_file_content = """
	  cc_library(
		name = "gtest",
		srcs = glob(
			 ["src/*.cc"],
			 exclude = ["src/gtest-all.cc"]
		),
		hdrs = glob([
			 "include/**/*.h",
			 "src/*.h"
		]),
		copts = ["-Iexternal/gtest/include"],
		linkopts = ["-pthread"],
		visibility = ["//visibility:public"],
	  )
	"""
)