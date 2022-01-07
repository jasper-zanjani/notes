# eBPF

eBPF is an extended version of the Berkeley Packet Filter (BPF). 
It is a sandboxed environment that allows code to be inserted into the running kernel. 
Kernel functionality must normally be extended by building an entirely new kernel with custom modules or upstream patching of the Linux kernel.

eBPF's architecture includes a JIT compiler that compiles the program's generic bytecode, which means eBPF programs run as efficiently as natively compiled kernel code.

eBPF programs can be bound to kernel events, such as receipt of a packet from the NIC.



## Glossary

**bpftool**{: # bpftool }
:   
    Core eBPF CLI tool.

    === ":material-fedora: Fedora"

        ```sh
        dnf install bpftool
        ```

    Display running eBPF programs 
    ```sh
    bpftool prog
    ```

    Display maps
    ```sh
    bpftool map show
    ```

*[L3AF]: Lightweight eBPF Application Foundation

**L3AF**{: #l3af }
:   
    Walmart Global Tech offering that allows management of multiple eBPF programs ("kernel functions" in L3AF parlance) using a control plane written in Go.

    L3AF's daemon **l3afd** exposes an API that can be used via HTTP requests.

    L3AF can orchestrate a sequence of kernel functions (called "chaining").


    ??? info "Resources"

        - [Introducing L3AF, a Platform to Launch and Manage eBPF Programs](https://www.youtube.com/watch?v=wc8_KGh_JfA)

*[XDP]: eXpress Data Path

**XDP**{ :#xdp }
:   
    XDP (eXpress Data Path) is a framework that makes high-speed packet processing possible within eBPF applications.
    XDP programs can be directly attached to a NIC, and they will be executed on receipt of every packet as an event callback.

    XDP programs can be attached to a NIC using one of the following models:
    
    - Generic XDP: loaded into the kernel as part of the ordinary **network path**
    - Native XDP: loaded by the NIC driver as part of its initial receive path
    - Offloaded XDP: loaded and executed on the NIC directly

    ??? info "Resources"

        - [eBPF XDP: the Basics and a Quick Tutorial](https://www.tigera.io/learn/guides/ebpf/ebpf-xdp/)