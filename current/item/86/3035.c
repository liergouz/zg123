
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 3; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8606);
        set_picid_2(8606);

        set_level(35);
        set_value(17000);
        set_max_lasting(7099);
        set("cp", 0);
        set("pp", 30);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
