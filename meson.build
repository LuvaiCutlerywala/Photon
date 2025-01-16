project('photon', 'c',
        version : '1.0.0',
        default_options : ['warning_level=3', 'c_std=c18'])

#Compile and install core internal libraries that is included in the compiler.

logging = shared_library('photon_logger', ['logging/logger.h', 'logging/logger.c'])
internals = shared_library('photon_internals', ['internal/internal_functions.h',
                                                'internal/internal_functions.c',
                                                'internal/internal_operations.h',
                                                'internal/internal_operations.c'], link_with : logging)
#Compile and install the actual interpreter.
include = include_directories('src/include')
source = ['src/main.c', 'src/lexer.c', 'src/token.c', 'src/reader.c', 'src/AST.c',
        'src/parser.c', 'src/visitor.c', 'src/internals_api.c', 'src/macros.c'
]

photon = executable(
        'photon',
        source,
        install : true,
        include_directories : include,
        link_with : [logging, internals]
)

test('test', photon)