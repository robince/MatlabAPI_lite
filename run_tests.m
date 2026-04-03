cd tests

sizes = [9 9 9 9 9 9 9];
typekind = {'real_c_double' 'integer_c_int8_t' 'integer_c_int16_t' 'integer_c_int32_t' 'integer_c_int64_t'};
castfun = {@double, @int8, @int16, @int32, @int64};
unsigned_input = {
    'integer_c_int8_t', @uint8, @int8;
    'integer_c_int16_t', @uint16, @int16;
};

% rank 0
xraw = 9;
for tki=1:length(typekind)
    xtest = castfun{tki}(xraw);
    fun = ['test_mx_' typekind{tki} '_0'];
    y = feval(fun, xtest);
    if ~isequal(y, 2*xtest)
        error('Doubling test failed for %s rank %d', typekind{tki}, 0);
    end
end

% unsigned input compatibility
% uint8/uint16 inputs are accepted by the int8/int16 entry points as long
% as the values stay within the corresponding signed range.
for uki=1:size(unsigned_input, 1)
    compat_typekind = unsigned_input{uki, 1};
    input_cast = unsigned_input{uki, 2};
    expected_cast = unsigned_input{uki, 3};

    xraw = 9;
    xtest = input_cast(xraw);
    y = feval([ 'test_mx_' compat_typekind '_0' ], xtest);
    expected = expected_cast(2 * double(xraw));
    if ~isequal(y, expected)
        error('Unsigned input compatibility failed for %s rank %d', compat_typekind, 0);
    end

    xraw = 9 * ones(9, 1);
    xtest = input_cast(xraw);
    y = feval([ 'test_mx_' compat_typekind '_1' ], xtest);
    expected = expected_cast(2 * double(xraw));
    if ~isequal(y, expected)
        error('Unsigned input compatibility failed for %s rank %d', compat_typekind, 1);
    end

    rank = 2:6;
    for ri=1:length(rank)
        xraw = 9 * ones(sizes(1:rank(ri)));
        xtest = input_cast(xraw);
        y = feval([ 'test_mx_' compat_typekind '_' num2str(rank(ri)) ], xtest);
        expected = expected_cast(2 * double(xraw));
        if ~isequal(y, expected)
            error('Unsigned input compatibility failed for %s rank %d', compat_typekind, rank(ri));
        end
    end
end

% rank 1
xraw = 9*ones(9,1);
for tki=1:length(typekind)
    xtest = castfun{tki}(xraw);
    fun = ['test_mx_' typekind{tki} '_1'];
    y = feval(fun, xtest);
    if ~isequal(y, 2*xtest)
        error('Doubling test failed for %s rank %d', typekind{tki}, 1);
    end
end

% other ranks
rank = 2:6;
for ri=1:length(rank)
    xraw = 9*ones(sizes(1:rank(ri)));
    size(xraw)
    for tki=1:length(typekind)
        xtest = castfun{tki}(xraw);
        fun = ['test_mx_' typekind{tki} '_' num2str(rank(ri))];
        y = feval(fun, xtest);
        if ~isequal(y, 2*xtest)
            error('Doubling test failed for %s rank %d', typekind{tki}, rank(ri));
        end
    end
end
