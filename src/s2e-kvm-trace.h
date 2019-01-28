///
/// Copyright (C) 2019, Cyberhaven
/// All rights reserved.
///
/// Licensed under the Cyberhaven Research License Agreement.
///

#ifndef S2E_KVM_TRACE_H

#define S2E_KVM_TRACE_H

#include <cpu/kvm.h>
#include <inttypes.h>

#include "FDManager.h"
#include "s2e-kvm-interface.h"
#include "syscalls.h"

namespace s2e {
namespace kvm {

class KVMTrace : public IFile {
private:
    int m_kvm_fd;

    KVMTrace(int fd) : m_kvm_fd(fd) {
    }

public:
    static IFilePtr Create();

    virtual int ioctl(int fd, int request, uint64_t arg1);
};

class KVMTraceVM : public IFile {
private:
    int m_kvm_vm_fd;

    KVMTraceVM(int vm_fd) : m_kvm_vm_fd(vm_fd) {
    }

public:
    static IFilePtr Create(int vm_fd);
    virtual int ioctl(int fd, int request, uint64_t arg1);
};

class KVMTraceVCPU : public IFile {
private:
    int m_kvm_vcpu_fd;

    KVMTraceVCPU(int vcpu_fd) : m_kvm_vcpu_fd(vcpu_fd) {
    }

public:
    static IFilePtr Create(int vcpu_fd);
    virtual int ioctl(int fd, int request, uint64_t arg1);
    virtual void *sc_mmap(void *addr, size_t len, int prot, int flags, int fd, off_t offset);
};
}
}

#endif
