
// �Զ����ɣ�/make/item/make97

inherit ITEM;

int get_item_color() { return 1; }
// ���������촦��
void create()
{
        set_name("��ӹ");
        set_picid_1(3802);
        set_picid_2(3802);
        set_unit("��");
        set_value(100000);
}

// ��������ȡ����
string get_desc() 
{ 
        return "��ϡ��Ʒ"; 
}
