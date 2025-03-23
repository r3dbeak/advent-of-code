
fileID = fopen('input/day03.in', 'r');
pattern = 'mul\((\d+),(\d+)\)';

result = 0;
while ~feof(fileID)
    line = fgetl(fileID);
    tokens = regexp(line, pattern, 'tokens');
    if ~isempty(tokens)
        for i = 1:length(tokens)
            token = tokens{i};
            num1 = str2double(token{1});
            num2 = str2double(token{2});
            result = result + num1 * num2;
        end
    end
end
fprintf('Result: %d\n', result);
fclose(fileID);