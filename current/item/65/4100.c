
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("����");
        set_picid_1(6580);
        set_picid_2(6580);

        set_level(100);
        set_value(27000);
        set_max_lasting(10299);
        set("dp", 85);
        set("pp", 63);

        setup();

        set_gender(1);
        set_head_code(47);
}

// ��������ȡ����
string get_desc()
{
        return "����";
}
