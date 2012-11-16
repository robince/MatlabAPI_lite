cd tests

sizes = [9 9 9 9 9 9 9];
typekind = {'real_c_double' 'integer_c_int8_t' 'integer_c_int16_t' 'integer_c_uint8_t' 'integer_c_uint16_t'};
castfun = {@double, @int8, @int16, @uint8, @uint16};

% rank 0
xraw = 9;
for tki=1:length(typekind)
    xtest = castfun{tki}(xraw);
    fun = ['test_mx_' typekind{tki} '_0'];
    y = eval([fun '(xtest)']);
    if y ~= 2*xtest
        error(sprintf('Doubling test failed for %s rank %d',typekind{tki},0));
    end
end

% rank 1
xraw = 9*ones(9,1);
for tki=1:length(typekind)
    xtest = castfun{tki}(xraw);
    fun = ['test_mx_' typekind{tki} '_1'];
    y = eval([fun '(xtest)']);
    if y ~= 2*xtest
        error(sprintf('Doubling test failed for %s rank %d',typekind{tki},0));
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
        y = eval([fun '(xtest)']);
        if y ~= 2*xtest
            error(sprintf('Doubling test failed for %s rank %d',typekind{tki},0));
        end
    end
end
