
fileID = fopen('input/day03.in', 'r');
pattern = 'mul\((\d+),(\d+)\)|(do\(\))|(don\''t\(\))';

result = 0;
readInstruction = true;
while ~feof(fileID)
    line = fgetl(fileID);
    tokens = regexp(line, pattern, 'tokens');
    if ~isempty(tokens)
        for i = 1:length(tokens)
            token = tokens{i};
            if strcmp(token{1},'do()')
                readInstruction = true;
            elseif strcmp(token{1},'don''t()')
                readInstruction = false;
            else
                if readInstruction
                    num1 = str2double(token{1});
                    num2 = str2double(token{2});
                    result = result + num1 * num2;
                end
            end
        end
    end
end
fprintf('Result: %d\n', result);
fclose(fileID);