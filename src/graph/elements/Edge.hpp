struct Edge{
	unsigned long s; //source
	unsigned long t; //target

	Edge()
	{
	}

	Edge(unsigned long s_p, unsigned long t_p )
	: s(s_p), t(t_p)
	{
	}

	bool operator==(const Edge & other) const
	{
		return (s == other.s && t == other.t)
			|| (s == other.t && t == other.s);
	}
};