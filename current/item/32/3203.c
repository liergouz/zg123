
// �Զ����ɣ�/make/item/make32a

inherit ITEM;
    inherit COMBINED;

// ��������������
//  int get_max_combined() { return 30; }

// ������ԭ������
int get_stuff_type() { return 144; }

// ���������촦��
void create()
{
        set_name("����");
        set_picid_1(3203);
        set_picid_2(3203);
        set_unit("��");
        set_value(20);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "ũ��Ʒ��һ��"; 
}
