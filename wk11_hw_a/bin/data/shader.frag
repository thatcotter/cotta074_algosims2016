#version 120

uniform float _r;
uniform float _g;
uniform float _b;

void main( void ) {
    gl_FragColor = vec4(_r, _g, _b, 1.0);
}