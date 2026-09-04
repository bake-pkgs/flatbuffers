import bake.build;
import std;

// flatbuffers runtime for bake. The core (FlatBufferBuilder / verify /
// reflection reads) is header-only; these four TUs are the runtime lib the
// upstream `flatbuffers` target contributes beyond flatc's code generators —
// enough for schema parsing (Parser), text generation, and the utilities the
// parser links against. flatc itself is not packaged.

int main() {
    bake::Builder b;
    const auto upstream = std::string(b.dep_src_dir("upstream"));

    b.sources({upstream + "/src/code_generators.cpp",
               upstream + "/src/idl_parser.cpp",
               upstream + "/src/idl_gen_text.cpp",
               upstream + "/src/util.cpp"})
        .public_headers(upstream + "/include");
    return b.build();
}
