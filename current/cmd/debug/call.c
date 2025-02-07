
#define CALL_ITEM_LOG   "gm/callitem.txt"       // ���������־
#define CALL_USER_LOG   "gm/calluser.txt"       // ��ҵ�����־

// �������ַ���->��������
mixed atom( string arg )
{
        mixed *m, m1, m2;
        mapping mp;
        object o;
        string s, s1, s2;
        int i, size;

        // ���ִ������
	if( !arg ) return arg;    // arg = all_trim(arg)

        // ���ֵ����
        if( strlen(arg) > 2 && arg[0..1] == "0x" && sscanf( arg, "%x", i ) ) return i;

	if( sscanf( arg, "%d", i ) ) return i;

        // �ַ��������
	if( sscanf( arg, "\"%s\"", s ) ) return s;

        // ��������
	if( o = find_any_object(arg) ) return o;

	// (: o, s :) �����
        if( sscanf( arg, "(:%s,%s:)", s1, s2 ) == 2 )
	{
		m1 = atom(s1);  m2 = atom(s2);
                // if( objectp(m1) && stringp(m2) ) return (: (object)m1, (string)m2 :);
        }

        // ({ m }) �����
	if( sscanf( arg, "({%s})", s ) )
	{
		m = explode( s, "," );
		size = sizeof(m);
		if( size && !m[0] ) return ({ });
		for( i = 0; i < size; i ++ ) m[i] = atom( m[i] );
		return m;
	}

        // ([ mp ])
	if( sscanf( arg, "([%s])", s ) )
	{
		mp = ([ ]);
		m = explode( s, "," );
		size = sizeof(m);
		if( size && !m[0] ) return ([ ]);
		for( i = 0; i < size; i ++ ) if( sscanf( m[i], "%s:%s", s1, s2 ) == 2 ) mp[ atom(s1) ] = atom(s2);
		return mp;
	}

	return arg;
}

// �����������
int main( object me, string arg )
{
        object obj;
        string str, func, param;
        mixed *Args, result;
        int i, j, size;

        if( me != this_player(1) || !is_god(me) ) 
        {
                notify( "��û���㹻��Ȩ�ޡ�" );
		return 1;
        }

        if( !arg )
        {
                notify( "��Ҫ����ʲô������" );
		return 1;
        }

        // ������->����(����)����ʽ����Ĵ���
        // ע�⣬�������һ���������ں����ж�
        if( sscanf(arg, "%s->%s(%s", str, func, param) != 3 ) 
        {
                notify( "��Ҫ����ʲô������" );
		return 1;
        }

        // param = all_trim(param);
        if( sizeof(param) == 1 && param[<1] == ')' ) param = "";
        if( sizeof(param) > 1 ) param = param[0..<2];
	if (str=="here")
	{
		obj = get_map_object(get_z(me));
	}
	else
        if( !( obj = find_any_object(str) ) ) 
        {
                notify( "���Ҳ���������塣" );
		return 1;
        }

        if( obj != me && func[0..2] != "get" ) 
        {
                if( obj->is_user() ) 
                        log_file( CALL_USER_LOG, sprintf( "%s %s(%s) call %s(%s)->%s(%s)\n",
                                short_time(), me->get_name(), me->get_id(), obj->get_name(), obj->get_id(), func, param ) );
                else    log_file( CALL_ITEM_LOG, sprintf( "%s %s(%s) call %s->%s(%s)\n",
                                short_time(), me->get_name(), me->get_id(), obj->get_name(), func, param ) );
        }

        // ת���ַ���Ϊ��Ӧ����������
        Args = ({ });
        for( i = 0, size = sizeof(param); i < size; i ++ ) 
        {
                if( param[i] == ' ' ) continue;
                else if( param[i] == '(' ) 
                {
                        for( j = i, i ++; param[i] != ')' && i < size; i ++ );
                        Args += ({ param[j..i] });
                        for( j = i, i ++; param[i] != ',' && i < size; i ++ );
                }
                else if( param[i] == '\"' ) 
                {
                        for( j = i, i ++; param[i] != '\"' && i < size; i ++ );
                        Args += ({ param[j..i] });
                        for( j = i, i ++; param[i] != ',' && i < size; i ++ );
                }
                else 
                {
                        for( j = i, i ++; param[i] != ',' && i < size; i ++ );
                        Args += ({ param[j..i-1] });
                }
        }

        // ת�������ִ�Ϊ��Ӧ��������
        for( i = 0, size = sizeof(Args); i < size; i ++ ) Args[i] = atom( Args[i] );

        Args = ({ func }) + Args;
        result = call_other(obj, Args);

        for( i = 1, size = sizeof(Args); i < size; i ++ ) Args[i] = sprintf( "%O",Args[i] );

        tell_user( me, "%O->%s(%s) = %O", obj, func, implode(Args[1..<1], ", "), result );

        return 1;
}
