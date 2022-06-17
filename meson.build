project('raop-player', 'c')

incdir = include_directories('.',
                             'tools'
                            )

src = ['tools/log_util.c',
        'src/raop_client.c',
        'src/rtsp_client.c',
        'src/aes.c',
        'src/aexcl_lib.c',
        'src/base64.c',
        'src/alac_wrapper.cpp',
        'src/aes_ctr.c',
        'src/raop_play.c'
]

libalac_proj = subproject('alac')
libalac_dep = libalac_proj.get_variable('libalac_dep')

libcurve25519_proj = subproject('curve25519')
libcurve25519_dep = libcurve25519_proj.get_variable('libcurve25519_dep')

libcrypto = dependency('libcrypto')

executable('raop_player',
                 src,
                 include_directories: incdir,
                 dependencies: [libalac_dep, libcurve25519_dep, libcrypto],
                 cpp_args: ['-Wall', '-g'])