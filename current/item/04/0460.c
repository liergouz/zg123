inherit ITEM;
inherit COMBINED;

int get_item_color() { return 1; }

// ���������촦��
void create()
{
        set_name("����");
        set_picid_1(3289);
        set_picid_2(3289);
        set_amount(1);
        set_value(40);
}

void reset()
{
        if( gone_time( get_drop_time() ) > 3000 )    // 100����
        {
                remove_from_scene();
                destruct( this_object() );
        }
}

// ��������ȡ����
int get_item_value() {return 8 ;}
int get_item_value_2() {return 8 ;}
string get_desc() 
{ 
        return "�����ı�֮һ"; 
}
