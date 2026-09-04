# flatbuffers

[FlatBuffers](https://github.com/google/flatbuffers) for bake — memory
efficient serialization library. v25.2.10.

The core (FlatBufferBuilder, verification, reads) is header-only; this
package adds the runtime TUs the upstream `flatbuffers` library target
contributes beyond flatc's code generators: schema parsing (`Parser`),
text generation, and the utilities they link against. `flatc` itself is not
packaged.

## Verification

Built and smoke-tested on `aarch64-apple-darwin`: schema + JSON parse to
binary via `flatbuffers::Parser`, then JSON round-trip with `GenerateText`.
Cross-compile-checked via kotatsu's `fbs` feature on musl / gnu /
windows-gnu.
