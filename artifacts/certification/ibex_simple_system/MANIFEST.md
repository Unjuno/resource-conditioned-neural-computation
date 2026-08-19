# Frozen RTNN Ibex Simple System certification artifact

This directory freezes the exact GitHub Actions artifact package used by the pinned Ibex RTL timing, exact-binary noninterference/BINSEC, and deterministic-memory audits.

- source Actions artifact ID: `9352155229`
- frozen ZIP SHA-256: `9150b0763e5d7b7c305441befdb4161ccf95612edd924b525f8388e06d9a86b0`
- contained ELF SHA-256: `234a7f46cf227a11f5d97f3c778cbb0c4ed4f7067f8994bcca86c4b08ff4e742`
- contained loadable BIN SHA-256: `266ecb70c723b2164f6fe9039f27d4cb49c4d7271d4aca0cf69f2692cdfdf7a1`
- pinned Ibex commit: `7b5df75a041affe56e8c235260f98a09b3319008`

The ZIP is the durable repository copy. Consumers must still unpack it and verify the contained ELF/BIN hashes before using any timing evidence. A different compiler artifact, RTL revision/configuration, memory integration, or physical target requires a new certification identity and timing binding.
