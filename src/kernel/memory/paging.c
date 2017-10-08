
// Page Directory Pointer Table needs to be aligned to atleast 0x20
uint64_t page_dir_ptr_tab[4] __attribute__((aligned(0x20)));

// 512 entries aligned to the page boundary
uint64_t page_dir[512] __attribute__((aligned(0x1000)));
uint64_t page_tab[512] __attribute__((aligned(0x1000)));

void init_paging(void)
{
	page_dir_ptr_tab[0] = (uint64_t)&page_dir | 1;
	page_dir[0] = (uint64_t)&page_tab | 3;

	// Mapping the first 2MiB
	unsigned int i, address = 0;
	
	for (i = 0; i < 512; i++)
	{
		// Mapping address and marking it writable
		page_tab[i] = address | 3;
		address = address + 0x1000;
	}

	asm volatile ("movl %cr4, %eax; bts $5, %eax; movl %eax, %cr4");
	asm volatile ("movl %%eax, %%cr3" :: "a" (&page_dir_ptr_tab));

	asm volatile ("movl %cr0, %eax; orl $0x80000000, %eax; movl %eax, %cr0;");
}
