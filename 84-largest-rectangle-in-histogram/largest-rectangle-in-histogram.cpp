class Solution {
public:
    int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    vector<int> left;
    vector<int> right;
    stack<pair<int, int>> st;

    // first find nearest smaller to left indeices
    for (int i = 0; i < n; i++)
    {
        if (st.empty())
        {
            left.push_back(-1);
        }
        else if (!st.empty() and st.top().first < heights[i])
        {
            left.push_back(st.top().second);
        }
        else
        {
            while (!st.empty() and st.top().first >= heights[i])
            {
                st.pop();
            }

            if (st.empty())
            {
                left.push_back(-1);
            }
            else
            {
                left.push_back(st.top().second);
            }
        }
        st.push({heights[i], i});
    }

    // find the nearest smaller to right
    // clear the stack as we using same stack
    while (!st.empty())
    {
        st.pop();
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (st.empty())
        {
            // if no smaller to left push n
            right.push_back(n);
        }
        else if (!st.empty() and st.top().first < heights[i])
        {
            right.push_back(st.top().second);
        }
        else
        {
            while (!st.empty() and st.top().first >= heights[i])
            {
                st.pop();
            }

            if (st.empty())
            {
                right.push_back(n);
            }
            else
            {
                right.push_back(st.top().second);
            }
        }
        st.push({heights[i], i});
    }
    reverse(right.begin(), right.end());

    // for (int i = 0; i < n; i++)
    // {
    //     cout << left[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << right[i] << " ";
    // }
    // cout << endl;

    int mxarea = 0;
    for (int i = 0; i < n; i++)
    {
        int l = abs(i - left[i]);
        int r = abs(i - right[i]);
        int width = l + r - 1;
        int area = width * heights[i];
        mxarea = max(mxarea, area);
    }
    return mxarea;
}
};