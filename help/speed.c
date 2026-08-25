#include <stdio.h>
#include <string.h>

int main()
{
    const char* archs[] = {
        "aix","ppc64",
        "android","386",
        "android","amd64",
        "android","arm",
        "android","arm64",
        "darwin","amd64",
        "darwin","arm64",
        "dragonfly","amd64",
        "freebsd","386",
        "freebsd","amd64",
        "freebsd","arm",
        "freebsd","arm64",
        "illumos","amd64",
        "ios","amd64",
        "ios","arm64",
        "js","wasm",
        "linux","386",
        "linux","amd64",
        "linux","arm",
        "linux","arm64",
        "linux","loong64",
        "linux","mips",
        "linux","mips64",
        "linux","mips64le",
        "linux","mipsle",
        "linux","ppc64",
        "linux","ppc64le",
        "linux","riscv64",
        "linux","s390x",
        "netbsd","386",
        "netbsd","amd64",
        "netbsd","arm",
        "netbsd","arm64",
        "openbsd","386",
        "openbsd","amd64",
        "openbsd","arm",
        "openbsd","arm64",
        "openbsd","ppc64",
        "openbsd","riscv64",
        "plan9","386",
        "plan9","amd64",
        "plan9","arm",
        "solaris","amd64",
        "wasip1","wasm",
        "windows","386",
        "windows","amd64",
        "windows","arm64"
    };
    for (unsigned char a = 0; a < sizeof archs / sizeof *archs; a+=2)
    {
      printf
      (
        "%s-%s-%s-a-goImageLibrary = bin/lib/static/a/go/%s/%s/%s/CImage.a\n\n",
        archs[a + 1],
        archs[a],
        !strcmp(archs[a],"windows")
        ? "pe"
        : !(strcmp(archs[a],"darwin") && strcmp(archs[a],"ios"))
        ? "machO"
        : !strcmp(archs[a+1],"wasm")
        ? "wasm"
        : "elf",
        !strcmp(archs[a],"windows")
        ? "pe"
        : !(strcmp(archs[a],"darwin") && strcmp(archs[a],"ios"))
        ? "machO"
        : !strcmp(archs[a+1],"wasm")
        ? "wasm"
        : "elf",
        archs[a],
        archs[a + 1]
      );
      printf
      (
        "build-%s-%s-%s-a-goImageLibrary: $(goImageLibrary)\n\t",
        archs[a + 1],
        archs[a],
        !strcmp(archs[a],"windows")
        ? "pe"
        : !(strcmp(archs[a],"darwin") && strcmp(archs[a],"ios"))
        ? "machO"
        : !strcmp(archs[a+1],"wasm")
        ? "wasm"
        : "elf"
      );
      printf
      (
        "GOOS=%s GOARCH=%s go build -buildmode=c-archive -o $(goImageLibrary) $(%s-%s-%s-a-goImageLibrary)\n\t",
        archs[a],
        archs[a+1],
        archs[a + 1],
        archs[a],
        !strcmp(archs[a],"windows")
        ? "pe"
        : !(strcmp(archs[a],"darwin") && strcmp(archs[a],"ios"))
        ? "machO"
        : !strcmp(archs[a+1],"wasm")
        ? "wasm"
        : "elf"
      );
      printf
      (
        "mv bin/lib/static/a/%s/%s/%s/Cimage.h src/include/lib/go\n\n",
        !strcmp(archs[a],"windows")
        ? "pe"
        : !(strcmp(archs[a],"darwin") && strcmp(archs[a],"ios"))
        ? "machO"
        : !strcmp(archs[a+1],"wasm")
        ? "wasm"
        : "elf",
        archs[a],
        archs[a + 1]
      );
    }
}