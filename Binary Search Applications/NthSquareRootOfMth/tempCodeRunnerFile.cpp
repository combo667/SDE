void BinSearchNthRoot(ll n, ll m)
{
    ll low = 0;
    ll high = m;

    while (low <= high)
    {
        ll mid = (low + high) >> 1;

        ll res = binExp(mid, n);
        if (res == m)
        {
            cout << mid;
            return;
        }
        else if (res < m)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << -1;
    return;
}

ll binExp(ll a, ll b)
{
    ll ans = 1;

    while (b)
    {
        if (b & 1)
        {
            ans = ans * a;
            b = b - 1;
        }
        else
        {
            b >>= 1;
            a = a * a;
        }
    }

    return ans;
}
