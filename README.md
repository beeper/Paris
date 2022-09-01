# Paris

SPM-powered SDK for working with private frameworks.

## Help me!

Currently, using Paris is a bit convoluted. [Due to a limitation set by SPM](https://forums.swift.org/t/confused-by-unsafe-flags-being-disallowed-in-dependencies/27359/34), Paris may only be depended on as a branch item or a commit hash due to its usage of `unsafeFlags`. This makes versioning difficult, and makes large, complex projects depending on Paris *very* difficult.

Paris depends on `unsafeFlags` to inject `/System/Library/PrivateFrameworks` into the framework search paths. Without this, you would need to do add the flags *everywhere*, and nobody wants that. *Nobody*.

I have no other known methods of linking to private frameworks. Contributions are more than welcome, and if anyone has any suggestions, please feel free to open an issue.
