%
% make.m - build script for MatlabAPI_lite
%

% set to false if you don't have PyF95++ and are just using checked out
% sources
PROCESS_TEMPLATES = true;
% mex options
DEBUG = false;
VERBOSE = false;
LARGEARRAY = true;

% Matlab doesn't use the normal system path so need the full path to
% executables
PYF95 = '/Users/robince/slash/bin/PyF95++';
% PyF95++ installs to a different python directory so need to set
% PYTHONPATH appropriately
PYF95_PP = '/Users/robince/slash/lib/python2.7/site-packages';
setenv('PYTHONPATH', PYF95_PP);
% I had to change the !# line in the PyF95++ to explicitly point to the
% current python since env inside Matlab gives the wrong one because of the
% path

if ispc
    OBJEXT = 'obj';
else
    OBJEXT = 'o';
end

%% Clean

if PROCESS_TEMPLATES
    delete *.F90
    delete *.f90
end
delete *.mod
delete(['*.' OBJEXT])
delete(['*.' mexext])
cd tests
if PROCESS_TEMPLATES
    delete *.F90
    delete *.f90
end
delete *.mod
delete(['*.' OBJEXT])
delete(['*.' mexext])
cd ..
%% Process templates

if PROCESS_TEMPLATES
    st = system([ PYF95 ' --sources="MatlabAPImx.F90T" --std="f03" -x'],'-echo');
    if st ~= 0
        error('Problem processing MatlabAPImx.F90T template')
    end
    
    cd tests
    st = system([ PYF95 ' --sources="test_mx.F90T instantiate.F90T" --std="f03" -x'],'-echo');
    cd ..
    if st ~= 0
        error('Problem processing test templates')
    end
end
%% Build mex

ARGS = {};
if LARGEARRAY,  ARGS{end+1} = '-largeArrayDims';
else            ARGS{end+1} = '-compatibleArrayDims'; end
if DEBUG,       ARGS{end+1} = '-g'; end
if VERBOSE,     ARGS{end+1} = '-v'; end


% MatlabAPImx
MEXARGS = ARGS;
MEXARGS{end+1} = '-c';
MEXARGS{end+1} = 'MatlabAPImx.F90';
mex(MEXARGS{:})

% MatlabAPImex
MEXARGS = ARGS;
MEXARGS{end+1} = '-c';
MEXARGS{end+1} = 'MatlabAPImex.f';
mex(MEXARGS{:})

%%
% Tests
cd tests
rank = 0:6;
typekind = {'real_c_double' 'integer_c_int8_t' 'integer_c_int16_t'};
for ri=1:length(rank)
    for tki=1:length(typekind)
        MEXARGS = ARGS;
        MEXARGS{end+1} = ['-I..' filesep];
        MEXARGS{end+1} = ['test_mx_' typekind{tki} '_' num2str(rank(ri)) '.F90'];
        MEXARGS{end+1} = fullfile('..',['MatlabAPImx.' OBJEXT]);
        MEXARGS{end+1} = fullfile('..',['MatlabAPImex.' OBJEXT]);
        mex(MEXARGS{:})
    end
end
cd ..
