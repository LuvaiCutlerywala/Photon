project('photon', 'c',
        version : '1.0.0',
        default_options : ['warning_level=3', 'c_std=c18'])

#Compile and install logging library that is included in the compiler.
logger = shared_library('photon_logger', ['logging/logger.c', 'logging/logger.h'])
internals = shared_library('photon_internal', ['internal/internal_functions.h',
                                               'internal/internal_functions.c',
                                               'internal/internal_operations.h',
                                               'internal/internal_operations.c'
                           ])

#Compile and install the actual compiler.
include = include_directories('src/include')
source = ['src/main.c', 'src/lexer.c', 'src/token.c', 'src/reader.c', 'src/AST.c',
        'src/parser.c', 'src/visitor.c'
]

photon = executable(
        'photon',
        source,
        install : true,
        include_directories : include,
        link_with : [logger, internals]
)

test('test', photon)