
#include <city.h>

string get_user_id(string id);

// �����������
int main( object me, string arg )
{
        object who, npc, user;
        mapping org, skls;
        string *name, file, result, userid, userid2;
        int id, number, skill, flag;
        int i, j, size;

        if( is_player(me) ) 
        {
                notify( "��û���㹻��Ȩ�ޡ�" );
		return 1;
        }

        if( !arg )    // ��ʾ���а���
        {
                if( mapp( org = CITY_ZHOU->get_2("org") ) && arrayp( name = keys(org) ) )
                {
                        result = sprintf( "Ŀǰ�İ����У�" );
                        for( i = 0, size = sizeof(name); i < size; i ++ ) 
                        	if (org[name[i]])
                                	result = sprintf( "%s%s%d.%s��", result, i % 8 ? "" : "\n", i + 1, name[i] );
                        tell_user(me, result);
                }
                else    tell_user(me, "Ŀǰû���κΰ��ɡ�");
        }
        else
        {	
                if( mapp( org = CITY_ZHOU->get_2("org") ) && arrayp( name = keys(org) ) )
                {
	                if(     objectp( who = CITY_ZHOU->get_2("org." + arg) )
	                ||  ( ( number = to_int(arg) ) 
	                &&      number > 0 && number <= sizeof(name) 
	                &&      objectp( who = CITY_ZHOU->get_2("org." + name[number - 1] ) ) ) )
	                {	
	        		size = who->sizeof_member_dbase();
	        		name = who->get_all_member();
	        		for( i = 0; i < size; i ++ )
	        		{
	        			id = to_int(name[i]);
	        			userid = who->get_member_id(id);	        
					if (userid==0)
					{
tell_user(me, sprintf("%d: %s �޷��ҵ��浵ID", id, name[i]));						
						continue;
					}	        						
	        			user = new( USER );       				        			
	        			user->set_id(userid);
	        			if( !user->restore() ) continue;
	        			if ( user->get_number()!=id) 
	        			{
	        				tell_user(me, sprintf("%d: %s �浵:%d id=%s", id, userid, user->get_number(), get_user_id(userid)));
	        				userid = get_user_id(userid);
	        				destruct(user);
	        				for (j=1;j<=6;j++)
	        				{
	        					if (j==1) userid2 = userid;
	        					else userid2 = sprintf("%s#%d", userid, j);
	        					user = new( USER );   
	        					user->set_id(userid2);
	        					if( !user->restore() ) continue;
	        					if ( user->get_number()==id)
	        					{
	        						who->set_member_id(id, userid2);	        					
tell_user(me, sprintf("%d: ���� %s", id, userid2));	        
								destruct(user);							
	        						break;
	        					} 
	        					if (j==6)
	        						tell_user(me, sprintf("%d: �޷��ҵ��浵", id));
	        					destruct(user);
	        				}
	        			}
	        			else 	        	
	        				destruct(user);		
	        		}
	        		tell_user(me, "�����ϡ�");
	                }
	                else    tell_user(me, "Ŀǰû��������ɡ�");
              	}
        }

        return 1;
}


string get_user_id(string id)
{
	int i, size;
	size = strlen(id);
	for (i=0;i<size;i++)
	{
		if (id[i]=='#'&& i<size-1)
			return id[0..i-1];
	}
	return id;
}