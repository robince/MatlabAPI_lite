classdef contigcomplex
% CONTIGCOMPLEX
% Represent a contigous (interlaced) complex variable for interpability 
% with mex files. This allows to return an interlaced complex variable 
% from Fortran without worrying about complex mex API and work with it
% in Matlab.
% This is a simple wrapper that implements basic functions
% like real, imag etc. and is more for convenience than performance

    properties
        data;
        shape;
    end

    methods
        function obj = contigcomplex(x,shape)
            % constructor
            if nargin > 1
                % construct from contiguous data
                if mod(numel(x),2) ~= 0
                    error('contigcomplex: raw data must have even number of elements')
                end
                if 2*prod(shape) ~= numel(x)
                    error('contigcomplex: shape does not match data')
                end
                obj.data = x(:);
                obj.shape = shape;
            else 
                % construct from existing matlab complex
                if isreal(x)
                    error('contigcomplex: single input should be complex')
                end
                obj.shape = size(x);
                obj.data = zeros(2*numel(x),1, class(x));
                obj.data(1:2:end) = real(x);
                obj.data(2:2:end) = imag(x);
            end
        end

        function re = real(x)
            re = reshape(x.data(1:2:end), x.shape);
        end

        function im = imag(x)
            im = reshape(x.data(2:2:end), x.shape);
        end

        function r = abs(x)
            r = sqrt( real(x).^2 + imag(x).^2 );
        end
        
        function th = angle(x)
            th = reshape(atan2(imag(x), real(x)), x.shape);
        end
        
        function y = conj(x)
            ydat = x.data;
            ydat(2:2:end) = -ydat(2:2:end);
            y = contigcomplex(ydat, x.shape);
        end
        
        function y = complex(x)
            y = complex(real(x), imag(x));
        end

    end
end

