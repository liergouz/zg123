
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("��Ƥ��ñ");
        set_picid_1(6634);
        set_picid_2(6634);

        set_level(65);
        set_value(16500);
        set_max_lasting(8199);
        set("dp", 57);
        set("pp", 42);

        setup();

        set_gender(2);
        set_head_code(55);
}

// ��������ȡ����
string get_desc()
{
        return "��Ƥ��ñ";
}
