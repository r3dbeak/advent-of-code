fileID = fopen('input/day02.in', 'r');

valids = 0;
while ~feof(fileID)
    line = fgetl(fileID);
    parts = strsplit(strtrim(line), ' ');
    x = str2double(parts);
    if isSafe(x)
        valids = valids +1;
    else
        % Try removing any number and check if its safe
        for i=1:length(x)
            xAlt = x; xAlt(i) = [];
            if isSafe(xAlt)
                valids = valids+1;
                break;
            end
        end
    end
    
end
fprintf('Number of valid reports %d\n',valids);
fclose(fileID);

function safe = isSafe(x)
    dx = diff(x);
    incValid = all(dx>=1 & dx<=3,2);
    decValid = all(dx<=-1 & dx >= -3,2);
    safe = incValid || decValid;
end