
// �Զ����ɣ�/make/item/make30

inherit ITEM;
inherit COMBINED;
// ��������������
int get_max_combined() { return 30; }

// ���������촦��
void create()
{
        set_name("ޤҶ");
        set_picid_1(3250);
        set_picid_2(3250);
        set_value(50);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "�������õ�ޤҶ"; 
}

void reset()
{
        if( gone_time( get_drop_time() ) > 2400 )    // 40����
        {
                remove_from_scene();
                destruct( this_object() );
        }
}