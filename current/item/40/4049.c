
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
        set_name("��Ƥ��");
        set_picid_1(4049);
        set_picid_2(4049);
        set_value(289);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "һ�ַ�����Ƥ��Ʒ��������Ʒ��"; 
}
