
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8650);
        set_picid_2(8650);

        set_level(35);
        set_value(17000);
        set_max_lasting(7099);
        set("cp", 0);
        set("pp", 40);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
