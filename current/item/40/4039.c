
// �Զ����ɣ�/make/item/make30

inherit ITEM;
    inherit COMBINED;

// ��������ȡװ����ɫ����ɫ
int get_item_color() { return 0; }

// ��������������
//  int get_max_combined() { return 30; }

// ���������촦��
void create()
{
        set_name("ţ��");
        set_picid_1(4039);
        set_picid_2(4039);
        set_value(220);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "һ�ֺܽ�ʵ�Ķ��ﾭ����������Ʒ��"; 
}
