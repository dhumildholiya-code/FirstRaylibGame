workspace "SimpleGame"
    architecture "x64"

    configurations {"Debug", "Release"}

    startproject "game"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "game"