
inherit ITEM;

// ���������촦��
void create()
{
        set_name("�����");
        set_picid_1(0096);
        set_picid_2(0096);
        set_unit("��");
        set_value(50);
        set_no_give(1);
        set_no_sell(1); 
}


int get_item_color() {return 2;}

// ��������ȡ����
int get_item_value() {return 8 ;}
int get_item_value_2() {return 8 ;}
string get_desc() 
{ 
        return "ѧϰǿ�����ɼ��ܵ����\n�ഫս��ϰ��֮������ѧϰ������ǿ������Ϊ����Ķ��ͣ��ʶ����������һ˵��";
}
